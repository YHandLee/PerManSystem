
#创建数据库
create database PerMan;
#进入数据库
use PerMan;

#创建员工表
create table empolyee
(
	e_id int not null,
	e_name varchar(10) not null,
	e_gander varchar(2) not null,
	e_age int not null,
	e_job varchar(30) null
);
#设置员工编号唯一
create unique index empolyee_e_id_uindex
	on empolyee (e_id);
#添加员工信息
insert into  empolyee values (0,'李煜昊','男',18,'BOSS'),(1,'张三','女',18,'产品经理'),(2,'翠花','男',25,'前端程序员'),
                             (3,'麻子','男',35,'后端工程师'),(4,'李小刀','男',20,'总经理'),(5,'汪柄','女',18,'测试');
#查询员工表所有信息
select * from empolyee;
#创建系统管理员表
create table manager (m_user varchar(10) not null,m_pwd varchar(16) not null);
#设置管理员名字唯一
create unique index manager_m_user_uindex
	on manager (m_user);
#添加系统管理员
insert into manager values ('lyh','123456'),('lxd','654321');
#查询管理员表所有信息
select * from manager;

#删除员工信息表
drop table empolyee;
#删除系统管理员表
drop table manager;
#删库跑路
drop database  perman;



