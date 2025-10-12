SELECT a.aone, a.atwo, COUNT(*) as counts
FROM (select a1.name as aone,a2.name as atwo from authors a1 join authors a2 on a1.paper_index=a2.paper_index) a
where a.aone <> a.atwo and a.aone<a.atwo
GROUP BY a.aone, a.atwo having COUNT(*)>1 order by counts desc;
