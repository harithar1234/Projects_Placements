select c.cited,p.index,p.title,p.venue,p.abstract,a.name
from paperss p join authors a on p.index = a.paper_index
 join
 (select c1.citee,c2.cited from citations c1 join citations c2 on c1.cited=c2.citee
  ) c on c.citee=a.paper_index order by c.cited;
