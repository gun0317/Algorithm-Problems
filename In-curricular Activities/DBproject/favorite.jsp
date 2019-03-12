<%@page import="java.sql.*, java.io.*" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
  <!DOCTYPE html>
  <html>
    <%
  String id = (String)session.getAttribute("id"); //사용자를 식별하기 위해 id를 받아옴
  out.println("**사용자: "+id);
  Connection conn;
  Statement stmt;
  boolean found = false;
  try{
  int r;
  Class.forName( "com.mysql.jdbc.Driver" );
  conn = DriverManager.getConnection( "jdbc:mysql://localhost:3306/dbproject?serverTimezone=UTC", "root", "xlsh5201" );
  stmt = conn.createStatement();
  ResultSet rs = stmt.executeQuery("select * from store");

%>
      <head>
        <meta charset="UTF-8">
          <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
            <meta http-equiv="X-UA-Compatible" content="ie=edge">
              <title>2014312971</title>
              <link rel="stylesheet" href="css/bootstrap.min.css">
                <link rel="stylesheet" href="css/index.css" type="text/css">

                </head>
                <body>

                    <div class="col-6" style="text-align:center;margin-left:25%;margin-bottom:15%;">
                    <button type="button" class="btn btn-info btn-block" onClick="location.href='recommend.jsp';">뒤로가기</button>
                    <button type="button" class="btn btn-info btn-block" onClick="location.href='index.html';">로그아웃</button>
                      <hr>
                        <b style="font-size:20px;">단골 식당 추가</b>
                        <hr>
                        <form action="favorite2.jsp" method="post">
                        상호
                          <select name="storeName">
                          <%
                            while(rs.next()){
                          %>
                            <option value=<%=rs.getString("storeName")%>><%=rs.getString("storeName")%></option>
                          <%
                              }
                          %>
                          </select>
                          점수
                          <select name="score">
                            <option value="1" selected="selected">1</option>
                            <option value="2">2</option>
                            <option value="3">3</option>
                            <option value="4">4</option>
                            <option value="5">5</option>
                          </select>
                            <br><br><br>
                          <button type="submit" class="btn btn-secondary btn-block">단골 식당 추가</button>
                          </form>
                        <hr>
                        <b style="font-size:20px;">단골 식당 목록 (Order by 점수)</b>
                        <p style="font-size:10px;"> query 문:<br>select * <br>FROM favorite f, store s <br>WHERE f.userId = '"+id+"' AND f.storeName = s.storeName <br>ORDER BY f.score DESC
                        </p>
                        <hr>
                          <table border="1" style="width:100%">
                            <tr>
                              <td>책임 관리자</td>
                              <td>상호</td>
                              <td>위치</td>
                              <td>점수</td>
                            </tr>
                            <%
                            rs = stmt.executeQuery("select * FROM favorite f, store s WHERE f.userId = '"+id+"' AND f.storeName = s.storeName ORDER BY f.score DESC");

                            while(rs.next()){

                                %>
                                <tr>
                                  <td><%=rs.getString("s.mgrId")%></td>
                                  <td><%=rs.getString("s.storeName")%></td>
                                  <td><%=rs.getString("s.loc")%></td>
                                  <td><%=rs.getString("f.score")%></td>
                                </tr>

                                <%


                                }
                          stmt.close(); conn.close();
                        }
                        catch( Exception ex )
                          {
                              out.println( ex.getMessage() );
                          }

                          %>

                                <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
                                <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
                                <script src="js/bootstrap.min.js"></script>
                              </body>

                            </html>
