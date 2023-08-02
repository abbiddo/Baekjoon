-- 코드를 입력하세요
SELECT CONCAT('/home/grep/src/', F.BOARD_ID, '/', F.FILE_ID, F.FILE_NAME, F.FILE_EXT)
FROM USED_GOODS_BOARD B JOIN USED_GOODS_FILE F
	USING (BOARD_ID)
WHERE F.BOARD_ID = (SELECT BOARD_ID
                   FROM USED_GOODS_BOARD
                   ORDER BY VIEWS DESC
                   LIMIT 1)
ORDER BY FILE_ID DESC