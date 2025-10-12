select c.cited,p.index,p.title,p.venue,p.abstract,a.name
from paperss p join authors a on p.index = a.paper_index
 join citations c on c.citee=a.paper_index order by c.cited;