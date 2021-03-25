## Mandatory Part
Error Management
Carry out AT LEAST the following tests to try to stress the error
management
- Pass an arbitrary file descriptor to the get_next_line function on
which it is not possible to read, for example 42. The function must
return -1.
- Check the error returns for read and malloc.
If there is an error, you must stop the evaluation.

## Testing
As the evaluator, you are expected to provide a main which will always check:
- The return value of the get_next_line.
- The line read is the line sent to the input, without the \n.
Test all the possible combinations of the following rules:

- Large BUFFER_SIZE (>1024)
- Small BUFFER_SIZE (< 8, and 1)
- BUFFER_SIZE exactly the length of the line to read
- 1 byte variant (+/-) between the line and the BUFFER_SIZE

- Read on stdin
- Read from a file

- (Multiple/Single) Long line (2k+ characters)
- (Multiple/Single) Short line (< 4 characters, even 1)
- (Multiple/Single) Empty line


These tests should allow you to verify the strength of the student's
get_next_line. If any fails, grade 0 on the project.

## Bonus
We will look at your bonuses if and only if your mandatory part is excellent. This means that you must complete the mandatory part, beginning to end, and your error management must be flawless, even in cases of twisted or bad usage. So if you didn't score all the points on the mandatory part during this defence bonuses will be totally ignored.

## Multiple fd reading
Perform the same tests as you did before, this time launch multiple instances of get_next_line with a
different file descriptor on each. Make sure that each get_next_line is returning the correct line,
combine with a non-existing fd to check for errors.

## Single static variable
Check the code and verify if there is indeed a single static variable. Give the points if that's the case.
