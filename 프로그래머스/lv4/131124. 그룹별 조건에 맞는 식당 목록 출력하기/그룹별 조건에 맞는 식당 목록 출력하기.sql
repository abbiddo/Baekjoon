-- 코드를 입력하세요
SELECT P.MEMBER_NAME, R.REVIEW_TEXT, DATE_FORMAT(R.REVIEW_DATE, '%Y-%m-%d') AS REVIEW_DATE
FROM MEMBER_PROFILE P JOIN REST_REVIEW R 
    USING (MEMBER_ID)
WHERE P.MEMBER_ID = (SELECT P.MEMBER_ID
                     FROM MEMBER_PROFILE P JOIN REST_REVIEW R
                        USING (MEMBER_ID)
                     GROUP BY MEMBER_ID
                     ORDER BY COUNT(*) DESC
                     LIMIT 1)
ORDER BY REVIEW_DATE, R.REVIEW_TEXT