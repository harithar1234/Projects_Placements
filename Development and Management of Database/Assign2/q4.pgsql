SELECT
  cited,
  COUNT(cited) AS number_citations 
FROM
  citations
GROUP BY 
  cited
ORDER BY 
  number_citations DESC
LIMIT 20;