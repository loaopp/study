# [openpyxl](https://openpyxl.readthedocs.io/en/stable/index.html)
[[package](https://openpyxl.readthedocs.io/en/stable/api/openpyxl.html#module-openpyxl)]
## 생성

1. Workbook 생성

		from openpyxl import Workbook	# from openpyxl import *
		wb = Workbook()		# 이때 워크북은 항상 1개의 sheet(이름은 "Sheet")를 가지고 생성된다.
		ws = wb.active		# 바로 1번째 sheet를 제어가능
		ws.title = "title"	# sheet명 변경


2. Worksheet 생성

		ws1 = wb.create_sheet("test")		# 자동으로 다음 위치에 추가
		ws2 = wb.create_sheet("test", 0)	# 가장 앞에 추가
		ws3 = wb.create_sheet("test", -1)	# 가장 뒤에 추가
		ws4 = wb.create_sheet("test", x)	# x위치에 추가


## Workbook 읽기
1. .xlsx

		wb = load_workbook("file_name.xlsx")

2. .xlsm

		wb = load_workbook("file_name.xlsm", keep_vba=True)

3. 읽기 전용

		wb = load_workbook("file_name.xlsx", read_only=True)

## Workbook 저장
1. 파일 저장

		wb = Workbook()
		wb.save("file_name.xlsx")	# 경고없이 덮어 씌울수 있음

2. [save the file to stream](https://openpyxl.readthedocs.io/en/stable/tutorial.html#saving-as-a-stream)


## 접근
1.	sheet 접근

		ws = wb["sheet name"]

	반복문 사용

		for sheet in workbook:
			print(sheet.title)

2. cell 접근

		value = ws['A1']
		ws['A2'] = value

	반복문사용에 적합

		value = ws.cell(row=3, column=2, value=10)	# cell object

	범위 접근(tuple로 반환)

		cell_range = ws["A1":"C2"]	# tuple of cell object
		col_range1 = ws[10]
		col_range2 = ws[3:6]
		row_range1 = ws["A"]
		row_range2 = ws["A:C"]

	Worksheet.iter_rows()

		for row in ws.iter_rows(min_row=1, max_row=2, min_col=3, max_col=4):
			for cell in row:
				print(cell)

		<Cell Sheet1.C1>
		<Cell Sheet1.D1>
		<Cell Sheet1.C2>
		<Cell Sheet1.D2>

	Worksheet.iter_cols()

		for col in ws.iter_cols(min_row=1, max_col=3, max_row=2):	#기본 min = 1
			for cell in col:
				print(cell)

		<Cell Sheet1.A1>
		<Cell Sheet1.A2>
		<Cell Sheet1.B1>
		<Cell Sheet1.B2>
		<Cell Sheet1.C1>
		<Cell Sheet1.C2>

	Worksheet.rows (generator object)

		ws = wb.active
		ws["C9"] = "Hi"
		tuple(ws.rows)

	Worksheet.columns

		ws = wb.active
		ws["C9"] = "Hi"
		tuple(ws.columns)

## 행, 열 추가

기본적으로 행이든 열이든 1줄만 추가된다

	ws.insert_rows(7)	# 7번행에 1행 추가
	ws.insert_columns(1)

2:3행, F:H열 삭제

	ws.delete_rows(2, 2)
	ws.delete_columns(6, 3)

## 제어

1. [moving range of cells](https://openpyxl.readthedocs.io/en/stable/editing_worksheets.html#moving-ranges-of-cells "Formulas가 있을 경우")

		ws.move_range("D4:F10", rows=-1, cols=2)	# 위로 1칸 오른쪽으로 2칸이동

2. merge cell

		ws.merge_cells("A2:D2")
		ws.merge_cells(start_row=2, start_column=1, end_row=4, end_column=4)

3. unmerge cell

		ws.unmerge_cells("A2:D2")
		ws.unmerge_cells(start_row=2, start_column=1, end_row=4, end_column=4)

4. 이미지 추가

		from openpyxl import Workbook
		from openpyxl.drawing.image import Image

		wb = Workbook()
		ws = wb.active
		img = Image("logo.png")
		ws.add_image(img, "A1")
		wb.save("logo.xlsx")

5. 셀 그룹화(숨기기... 좀 다르긴한데..)

		import openpyxl

		wb = openpyxl.Workbook()
		ws = wb.active
		ws.column_dimensions.group("A", "D", hidden=True)
		ws.row_dimensions.group(1, 10, hidden=True)
		wb.save("fold.xlsx")

6. 메모

		from openpyxl.comments import Comment

		comment = Comment(text="A comment", author="Author's Name")
		comment.width = 300
		comment.height = 50
		ws["A1"].comment = comment

7. [폰트변경](https://openpyxl.readthedocs.io/en/stable/styles.html#working-with-styles "자세히")

		cell.font = Font(name='Courier', size=36)

## 특이사항
1. workbook 사이의 worksheet를 복사할수 없다
2. workbook이 읽기모드 혹은 쓰기모드일때 worksheet를 복사할수 없다
3. cell(값, 스타일, 하이퍼링크, 코맨트) 그리고 worksheet(including dimensions, format and properties)는 복사가능 하지만 그외는 불가능
4. 처음 sheet가 생성될시(메모리에 적재) cell은 존재하지 않는다. 처음 cell에 __접근(accessed)__ 될때 비로소 생성된다.
	```
	for x in range(1, 100):
		for y in range(1, 100):
			ws.cell(y, x)	# 사용하지 않는다

	사용하지도 않는데 100 x 100 cell을 만들 이유가 없기때문
	```
5. 퍼포먼스 이슈때문에 Worksheet.iter_cols(), Worksheet.columns()는 read_only mode에서 사용할수 없다
6. openpyxl은 이미지와 차트는 읽을수 없다. 그래서 workbook을 읽고 그대로 저장할 경우 이미지와 차트 내용을 잃을수 있다.
7. 쓰기모드로 workbook을 생성(Workbook(write_only=True))했을 경우 기본 worksheet가 제공되지 않는다. 그렇기 때문에 create_sheet()로 한번 생성해야한다
8. 쓰기모드일 경우 append()로만 cell입력 가능하다
9. 쓰기모드일 경우 단 한번만 저장가능하다. 이후 저장이나 입력 할경우 openpyxl.utils.exceptions.WorkbookAlreadySaved Exception이 발생한다.
