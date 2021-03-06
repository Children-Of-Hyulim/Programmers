-- 이름이 없는 동물의 아이디
SELECT ANIMAL_ID FROM ANIMAL_INS WHERE NAME IS NULL

-- 최댓값 구하기
SELECT MAX(DATETIME) FROM ANIMAL_INS

-- 모든 레코드 조회하기
SELECT * FROM ANIMAL_INS ORDER BY ANIMAL_ID ASC

-- 역순 정렬하기
SELECT NAME, DATETIME FROM ANIMAL_INS ORDER BY ANIMAL_ID DESC

-- 이름이 있는 동물의 아이디
SELECT ANIMAL_ID FROM ANIMAL_INS WHERE NAME IS NOT NULL

-- 아픈 동물 찾기
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS WHERE INTAKE_CONDITION = 'Sick'

-- 어린 동물 찾기
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS WHERE INTAKE_CONDITION != 'Aged'

-- 동물의 아이디와 이름
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS ORDER BY ANIMAL_ID

-- 여러 기준으로 정렬하기
SELECT ANIMAL_ID, NAME, DATETIME FROM ANIMAL_INS ORDER BY NAME, DATETIME DESC

-- 상위 n개 레코드
SELECT NAME FROM ANIMAL_INS WHERE DATETIME = (SELECT MIN(DATETIME) FROM ANIMAL_INS)