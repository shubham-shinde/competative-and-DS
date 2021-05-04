CREATE TABLE puzzle (
	col1 integer,
	col2 integer,
	col3 integer,
	UNIQUE (col1, col2)
);

insert into puzzle (col1, col2, col3)
values
(1,1,1),
(1,2,2),
(2,1,9),
(2,2,6),
(3,2,4),
(3,3,5),
(3,4,6);

insert into puzzle (col1, col2, col3)
values
(1,1,10),
(1,2,22),
(2,12,19),
(2,2,16),
(3,21,14),
(3,33,51),
(3,40,61);

/* You should get the back */
/* col1|col2|col3 */
/* ----- */
/* 1 2 2 */
/* 2 1 9 */
/* 3 4 6 */

/* Join with selected items from sub query of max */
select puz1.* from puzzle puz1 join (select col1, max(col3) as col3_max from puzzle group by col1) puz2 on puz2.col3_max = col3 and puz2.col1 = puz1.col1;

/* LEFT JOIN  where max element should have second col null, then where with null */
select p1.* from puzzle p1 left join puzzle p2 on p1.col1 = p2.col1 and p1.col3 < p2.col3 where p2.col1 is null;

/* nth maximum query */
select col1, col2, col3 from puzzle order by col3 desc limit 0, 1;

/* nth maximum value elements */
select * from puzzle where col1 = (select col1 from puzzle group by col1 order by col1 desc limit 1,1);


Error Code: 1055. Expression #2 of SELECT list is not in GROUP BY clause and contains nonaggregated column 't.col2' which is not functionally dependent on columns in GROUP BY clause; this is incompatible with sql_mode=only_full_group_by


