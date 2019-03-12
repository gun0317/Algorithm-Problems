# -*- coding: utf-8 -*-
import ast
from scipy import spatial
import operator
from konlpy.tag import Kkma

movie_titles=[]
vector_list=[]

movie_dict = {}

with open('movie_titles(ver2).txt', 'r') as f:
    for line in f:
        movie_titles.append(line[:-1])
with open('vector_list(ver2).txt', 'r') as v:
    for line in v:
        line = line[:-1]
        vector = ast.literal_eval(line)
        vector_list.append(vector)


count = 0
for i in movie_titles:
    movie_dict[i] = vector_list[count]
    count+=1

def cosine_distance(cosine_vector,comparison_vector):
    result = 1 - spatial.distance.cosine(cosine_vector, comparison_vector)
    return result
def morphy(review):
    stop = ["있다", "다는", "은데", "특히", "있었", "동안", "면서", "을까", "해하", "어떤", "한때", "어야", "듯이", "ㄴ다", 'Story', "cinepark",
            "co", "kr", "Review", "★★★★★", "★★★★", "★★★", "★★", "★", '있', '하', '것', '들', '그', '되', '수', '이', '보', '않',
            '없', '나', '사람', '주', '아니', '등', '같', '우리', '때', '년', '가', '한', '지', '대하', '오', '말', '일', '그렇', '위하', '때문',
            '그것', '두', '말하', '알', '그러나', '받', '못하', '일', '그런', '또', '문제', '더', '사회', '많', '그리고', '좋', '크', '따르', '중',
            '나오', '가지', '씨', '시키', '만들', '지금', '생각하', '그러', '속', '하나', '집', '살', '모르', '적', '월', '데', '자신', '안', '어떤',
            '내', '내', '경우', '명', '생각', '시간', '그녀', '다시', '이런', '앞', '보이', '번', '나', '다른', '어떻', '개', '전', '들', '사실',
            '이렇', '점', '싶', '말', '정도', '좀', '원', '잘', '통하', '소리', '놓']

    try:
        kkma = Kkma()
        morphs = kkma.morphs(review)
        morphs_complete = []
        for i in morphs:
            if i not in stop and len(i) > 1:
                morphs_complete.append(i)


    except TypeError:
        print("TypeError has ocurred")
    return morphs_complete


#feat은 sad, horror 같은 feature 유의어 사전
#mor는 사용할 morphs (리뷰)
def featureDetector(feat, mor):
    cnt = 0.0
    for w in mor:
        if w in feat:
            cnt+=1
            if w in importantWords:
                cnt+=1
            if w in unimportantWords:
                cnt-=0.5
    return cnt

def featureNormalization(feature):
    total = 0
    for i in feature:
        total += i
    if total == 0:
        total = 1
    for i in range(len(feature)):feature[i] /= total
    return feature

def featurizer(feat):
    featStr = ','.join(feat)
    feat = morphy(featStr)
    feat = set(feat)
    return feat

def featureVectorizer(morphs):
    featureVector = []

    for i in feature_titles:
        featureVector.append(featureDetector(globals()[i], morphs))

    # 정규화
    featureNormalization(featureVector)

    return featureVector

sad = {'눈물나','사고', '사망','고독','자살', '알코올', '신파', '상처', '치유', '슬프','초라','비극','통탄', '애석', '원통', '비참', '애통', '애처로', '우울', '아프', '서럽', '침통', '비통', '비탄', '애틋', '서글프', '원통', '섧', '눈물', '침울', '무력', '버림받', '그림자', '그늘', '걱정', '근심','참혹', '참상', '시한부', '이별', '감성적', '싹트'}

horror = {'무섭', '목숨', '오싹', '긴장', '추격', '목숨','오싹', '시체', '잡아먹', '엽기', '정체불명', '묶이', '자살', '고문','살해', '괴담', '탈출', '살점', '끔찍하', '찌푸리', '질색', '죽이려','공포', '불안', '경악', '두려', '긴장', '숨통', '호러', '무서', '겁','주저', '오금', '가위', '악몽', '불안전', '위협', '살인', '살벌', '소름', '귀신', '괴물', '살인마', '실종', '흉가', '잔인','잔혹', '참혹', '참상','고어', '하드코어', '끔찍', '징그러', '흉하', '소름', '역겨', '벌레', '썩은', '흉측', '살인', '쏘우', '복수', '구역질', '토', '피', '살인','두려움'}

action = {'흥미진진','재미있','재미','재밌','악당', '미션', '스파이', '간첩', '007', '경찰','대역', '스턴트', '액션', '대규모', '세트장', '헐리우드', '훈련' ,'격투','대결','싸우','할리우드','사냥감','죽이','총격전','경찰관','마블','인도자','구출','악당', 'DC', 'Marvel'}

family = {'쌍둥이',  '보호', '따뜻', '가정적','임신', '고양이', '키우던', '애정', '각별', '동거', '홀로', '고향', '자살', '친엄마', '힐링', '가족적', '우애', '형제', '자매', '남매', '교훈', '가문', '물려받', '노총각','고명딸','명절', '휴먼', '성탄절','크리스마스이브','남동생','성장','소년','소녀','수련','가족','일족','집','혈통','종족','가구','친척','혈연','관계','자손','가정','아들','딸', '아버지', '어머니','아빠','엄마','부부','남편','아내','결혼','러브','이혼','임신','불임', '할아버지', '할머니', '손자', '손녀', '손주', '이모', '삼촌', '조카', 'love', 'affair', '감동', '입양','고향'}

SF= {'흥미진진','재미있','재미','재밌','외계', '세기', '태양계', '종족', '로봇', '재난', '우주인', '산소','지구', '우주','미래','과학','외계인','행성', '블랙홀','가상'}

love = {'매혹','인연', '보호', '따뜻', '동거', '각별', '임신', '멜로', '운명적', '만남', '짝사랑', '감동','로맨스','사랑','연인','호감','소중','매력','로맨틱','러브','애정','첫눈','이끌리','감정','남녀','관계','남편','아내','친분','재회','첫만남','결혼','러브','동성','성적','이별','애원','섹스','마음', '첫사랑', '행복', '낭만적', '연애관','몸매','욕망','운명론','속마음','청혼','낭만'}

hero = {'흥미진진','재미있','재미','재밌','대규모', '세트장', '헐리우드','거대','화려','넘치','장엄','현란','압도적','아이맥스', '블록버스터', '특수', '스케일', '분장','효과', '활약', '파트너','정의', '종말', '영웅','용맹','용기','대담','불굴','씩씩','히어로','마블','디씨','캡틴','리더','지도자','인도자','구출','악당', 'DC', 'Marvel'}

comedy = {'흥미진진','재미있','재미','재밌','배꼽','노총각', '유머러스하', '재미있', '코미디', '유머', '명절', '웃기', '재미있는', '웃으', '유쾌', '떠들썩', '즐거운','코미디언',}

queer = {'동성애', '게이', '레즈', '레즈비언', '트렌스젠더', '퀴어', '동성'}

feminism = {'여권','여성','페미니즘', '양성', '페미'}

time_travel = {'흥미진진','재미있','재미','재밌','타임', '돌아가', '퓨처', '타임머신', '시간여행', '미래'}

school = {'성적','청춘','성장', '명량', '고딩', '고등학생', '고등학교', '학교', '성장통', '성장기', '선생님', '학생', '교생', '교복', '사춘기', '짝사랑', '학원물', '청춘', '첫사랑','대학','청년'}

kid = {'아동용', '공주','애니', '극장판', '애니메이션', '캐릭터', '성우', '더빙', '어린이', '초등학생', '만화', 'TV시리즈','디즈니'}

docu = {'박근', '진지', '다큐', '다큐멘터리', '실화','현실','기록','메세지'}

disaster = {'대피', '환경', '오염', '온난','사고', '대책', '안보', '감염', '좀비', '바이러스', '사살', '시신', '생존자', '살아남', '목숨', '죽음', '희생', '지구', '진상','재난', '재해', '구조', '재앙', '멸망', '폭풍', '침몰', '전쟁', '대피'}

political = {'박근', '노무', '혁명', '정부', '시위', '투표', '정권', '퇴진', '정치', '노무현', '공화국', '민주주의', '독재', '대통령', '인권', '참정권', '운동', '노예','KKK','부조리','윤리적','정치적','메세지','역사','시대'}

war = {'병사', '무술', '침략', '명나라', '국방장관', '군부', '안보', '공산당', '대책', '미사일', '기지', '소련', '미군', '공군', '해군', '전투', '전우애', '전선', '휴전', '대대장', '북진', '남하', '부상병', '탱크', '폭탄', '냉전', '아군', '적군', 'GP', '초소', '전쟁', '소대원', '이병', '일병', '상병', '병장', '북한', '총', '칼', '공습'}

thriller = {'흥미진진','재미있','재미','재밌','무장', '강도', '긴장감', '추격전','납치','복수극','인신매매', '쫓겨나', '어둠', '죽이', '서스펜스', '박진','무섭', '스릴러','폭력','피해자'}

crime = {'재미있','재미','재밌','누아르', '카지노', '밀항','밀입국','무장', '강도', '수사물', 'FBI','납치', '추격전', '사기', '죽이','인신매매','조직', '고스톱', '도박', '도박장','살인', '청부', '욕망', '파멸', '추락', '알코올', '중독', '심문', '강력계', '범죄', '마약', '도둑', '조폭', '형사', '경찰관','증거','기소','단속','불법','격투','범죄','마약','수사망','폭력','피해자','사건'}

twist = {'재미있','재미','재밌','반전', '반전있'}

music= {'교향곡','악장','왈츠','피아노','선율','재즈','연주','밴드','뮤지컬','음악','리드미컬하','리드미컬','멜로디','공연','무대','악기','조율','대중가요','노래','건반','기타','안무','뮤직비디오','희극'}

genius={'재미있','재미','재밌','추리', '두뇌','게임','베팅','배팅','설계','경기','대학','거물','카드','도박','천재','아이비',}

fantasy={'흥미진진','재미있','재미','재밌','반지', '요술', '지팡이', '마법', '빗자루', '엘프', '제왕', '오크', '주문', '마법사', '판타지', '드래곤', '롤링', '워프', '해리','환상'}

sports = {'흥미진진','재미있','재미','재밌','선수', '대결', '스포츠', '운동', '농구', '축구', '하키', '역경', '우승', '야구', '투수', '투구', '공격수', '수비수', '승부'}

religious = {'천사', '악마', '미사', '수녀', '성당', '세례', '십자가', '예수', '사제', '바티칸', '교황', '영혼', '종교적', '목사','교회','참배','종교인','선교사','피어스','템플','하느님','스님','미카엘','진리','큰스님','불교','계도','부처','성경','구절'}

feature_titles = ['sad','horror','action','family','SF','love','hero','comedy','queer','feminism','time_travel','school','kid','docu','disaster','political','war','thriller','crime','twist','music','genius','fantasy','sports','religious']
##가중치주기:
importantWords = {'공포','슬프','눈물','호러','귀신','괴물','살인','액션','할리우드','헐리우드','마블','DC','Marvel','가족적','명절','멜로','섹스','연애','결혼','영웅','히어로','웃기','웃으','코미디','코메디','페미니즘','동성애','게이','레즈','타임머신','시간여행','학교','성장기','첫사랑','아동용','애니','극장판','애니메이션','더빙','만화','디즈니','재난','재앙','민주주의','역사','병사','아군','전쟁','북한','긴장감','서스펜스','박진','스릴러','범죄','조폭','형사','폭력','반전','반전있','음악','선율','밴드','노래','공연','추리','두뇌','천재','마법','마법사','판타지','스포츠','선수','종교적','하나님','하느님','스님','불교','우주'}
unimportantWords = {'흥미진진','재미있','재미','현란','효과','블록버스터','거대'}


#stops = ["★★★★★", "★★★★", "★★★", "★★", "★", '있', '하', '것', '들', '그', '되', '수', '이', '보', '않', '없', '나', '사람', '주', '아니', '등', '같', '우리', '때', '년', '가', '한', '지', '대하', '오', '말', '일', '그렇', '위하', '때문', '그것', '두', '말하', '알', '그러나', '받', '못하', '일', '그런', '또', '문제', '더', '사회', '많', '그리고', '좋', '크', '따르', '중', '나오', '가지', '씨', '시키', '만들', '지금', '생각하', '그러', '속', '하나', '집', '살', '모르', '적', '월', '데', '자신', '안', '어떤', '내', '내', '경우', '명', '생각', '시간', '그녀', '다시', '이런', '앞', '보이', '번', '나', '다른', '어떻', '개', '전', '들', '사실', '이렇', '점', '싶', '말', '정도', '좀', '원', '잘', '통하', '소리', '놓']


#stopword: 2글자 이상 단어 중 필요 없는 단어 계속 추가해서 필터링!


def query_processing(q):
    query = morphy(q)
    qVector = featureVectorizer(query)
    return qVector

def similar_movie(movie_title):
    cosine_vector = movie_dict[movie_title]
    max_index = cosine_vector.index(max(cosine_vector))
    cosine_dict = {}
    for i in range(len(movie_titles)):
        ##
        dist = cosine_distance(cosine_vector,vector_list[i])
        cosine_dict[movie_titles[i]]=dist
        sorted_dict = sorted(cosine_dict.items(), key=operator.itemgetter(1))

    rsorted_dict = sorted_dict[::-1]
    str_result=""
    for i in range(1,6):
        str_result += "<"+str(i)+"순위> "+str(rsorted_dict[i][0]) + " (유사도: " + str(rsorted_dict[i][1]) + ")"
        file_path = './cine21/' + rsorted_dict[i][
            0] + '.txt'
        with open(file_path, 'r', encoding='UTF8') as f:
            a = f.read()
            splited_list = a.split(".")
            stop = True
            for i in globals()[feature_titles[max_index]]:
                if (i not in unimportantWords):
                    for j in splited_list:
                        if i in j:
                            str_result+="\n특징 키워드: " + i + "\n리뷰 중 문장: " + j + '.\n \n'
                            stop = False
                            break
                if stop == False:
                    break
    str_result = str_result.split("\n")
    return str_result

def query_movie(qVector):
    cosine_vector = qVector
    max_index = qVector.index(max(qVector))

    cosine_dict = {}
    for i in range(len(movie_titles)):
        ##
        dist = cosine_distance(cosine_vector,vector_list[i])
        cosine_dict[movie_titles[i]]=dist
        sorted_dict = sorted(cosine_dict.items(), key=operator.itemgetter(1))

    rsorted_dict = sorted_dict[::-1]
    str_result = ""
    for i in range(0, 5):
        str_result += "<"+str(i+1)+"순위> "+str(rsorted_dict[i][0])+" (유사도: "+ str(rsorted_dict[i][1]) + ")"
        file_path = './cine21/' + rsorted_dict[i][
            0] + '.txt'
        with open(file_path, 'r', encoding='UTF8') as f:
            a = f.read()
            splited_list = a.split(".")
            stop = True
            for i in globals()[feature_titles[max_index]]:
                if (i not in unimportantWords):
                    for j in splited_list:
                        if i in j:
                            str_result += "\n특징 키워드: " + i + "\n리뷰 중 문장: " + j + '.\n \n'
                            stop = False
                            break
                if stop == False:
                    break
    str_result = str_result.split("\n")
    return str_result

def recommend(mode, inputStr):
    ##query 진행 모드
    if (mode == 1):
        qVector = query_processing(inputStr)
        query_movie(qVector)

    ##유사한 영화 찾기 모드
    if (mode == 2):
        similar_movie(inputStr)

#print(recommend(2,'마션(2015)'))
