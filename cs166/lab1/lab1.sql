create table Students(sid numeric(9, 0), name text, grade float);
insert into Students values(860507041, 'John Anderson', 3.67);
insert into Students values(860309067, 'Tom Kamber', 3.12);
select * from Students where sid=860507041;
insert into Students values(860304039, 'George Haggery', 3.67);
select * from Students where grade=3.67;
