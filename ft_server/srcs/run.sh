#!/bin/bash

openssl req -newkey rsa:4096 -sha256 -days 365 -nodes -x509 \
		-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=yejeon" \
		-keyout /etc/ssl/private/localhost.dev.key \
		-out /etc/ssl/certs/localhost.dev.crt
#chmod 755 /etc/ssl/certs/localhost.dev.crt
#chmod 755 /etc/ssl/private/localhost.dev.key

mv ./localhost.conf /etc/nginx/sites-available/localhost
ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost
rm -rf /etc/nginx/sites-enabled/default


service mysql start

echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password


mkdir $DIR_PHPMYADMIN
tar -xf $NAME_PHPMYADMIN --strip-components=1 \
	-C $DIR_PHPMYADMIN
rm -rf $NAME_PHPMYADMIN
mv ./config.inc.php $DIR_PHPMYADMIN


mkdir $DIR_WORDPRESS
tar -xf $NAME_WORDPRESS --strip-components=1 \
	-C $DIR_WORDPRESS
rm -rf $NAME_WORDPRESS
mv ./wp-config.php $DIR_WORDPRESS


chown -R www-data /var/www/*
chmod -R 755 /var/www/*
chmod 755 ./auto_index.sh

service php7.3-fpm start
service nginx start
bash
