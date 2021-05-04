CREATE TABLE category (
	id integer,
	name varchar
);


CREATE TABLE product (
	id integer,
	name varchar,
	category_id integer
);

insert into category (id, name)
values
(1,"Phone"),
(2,"Laptop");

insert into product (id, category_id, name)
values
(1,1,"Iphone"),
(2,2,"Asus Laptop"),
(3,1,"Samsung galaxy");
