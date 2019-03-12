import pandas as pd
import numpy as np
from gensim.models import Word2Vec
from sklearn.cluster import KMeans
from sklearn.ensemble import RandomForestClassifier
from konlpy.tag import *

totalreview = open('data/total.txt',encoding='UTF8').read()

#stopword: 2글자 이상 단어 중 필요 없는 단어 계속 추가해서 필터링!
stop = ["있다","면서","다는","은데","특히","있었","동안","면서","을까","해하","어떤","한때","어야","듯이","ㄴ다",'story']
stop = set(stop)

def morphy(review):
    '''    
    pos = okt.pos(review)
    st = ""
    for i in pos:
        if((i[1] == 'Adjective' or i[1] == 'Adverb')):
            st += " "
            st += i[0]
    '''
    kkma = Kkma()
    morphs = kkma.morphs(review)
    #morphs = [w for w in morphs if ((w not in stop) and (len(w)>1))]
    return morphs

print("분석 시작")
morphs = morphy(totalreview)
print("분석 완료")
print(morphs[:100])
