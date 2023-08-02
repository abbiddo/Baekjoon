-- 코드를 입력하세요
SELECT A.AUTHOR_ID, A.AUTHOR_NAME, B.CATEGORY, SUM(S.SALES * B.PRICE)
FROM BOOK B JOIN AUTHOR A USING(AUTHOR_ID)
	JOIN BOOK_SALES S USING (BOOK_ID)
WHERE MONTH(S.SALES_DATE) = 1
GROUP BY AUTHOR_ID, CATEGORY
ORDER BY AUTHOR_ID, CATEGORY DESC
