from cosine_test import *
from flask import Flask, render_template, request, flash
app = Flask(__name__)

@app.route('/')
def home():
   return render_template('index.html')

@app.route('/query_result',methods = ['POST', 'GET'])
def Qresult():
   if request.method == 'POST':
      input_string = request.form.get('query')
      qVector = query_processing(input_string)
      result=query_movie(qVector)
      return render_template("result_test.html",result = result)

@app.route('/movie_result', methods=['POST', 'GET'])
def Mresult():
   if request.method == 'POST':
      input_string = request.form.get('title')
      result= similar_movie(input_string)
      return render_template("result_test.html",result = result)



if __name__ == '__main__':
   app.run(debug = True)