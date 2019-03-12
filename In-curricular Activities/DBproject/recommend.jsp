<%@page import="java.sql.*, java.io.*" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
  <!DOCTYPE html>
  <html>
    <%
  String id = (String)session.getAttribute("id"); //사용자를 식별하기 위해 id를 받아옴
  out.println("**사용자: "+id);
  Connection conn;
  Statement stmt;
  boolean found = false;

%>
      <head>
        <meta charset="UTF-8">
          <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
            <meta http-equiv="X-UA-Compatible" content="ie=edge">
              <title>2014312971</title>
              <link rel="stylesheet" href="css/bootstrap.min.css">
                <link rel="stylesheet" href="css/index.css" type="text/css"></head>
                <body>
                  <div class="row">
                    <div class="col-3 food-left">
                      <img class="food-left" src="img/pasta.jpg"/>
                      <img class="food-left" src="img/bibim.jpg"/>
                      <img class="food-left" src="img/chicken.jpg"/>
                    </div>
                    <div class="col-6" style="text-align:center;">
                      <hr>
                        당신이 평가한 점수
                        <hr>
                          <table border="1" style="width:100%">
                            <tr>
                              <td>한식</td>
                              <td>일식</td>
                              <td>양식</td>
                              <td>중식</td>
                              <td>분식</td>
                            </tr>
                            <%
                        try{
                        int r;
                        Class.forName( "com.mysql.jdbc.Driver" );
                        conn = DriverManager.getConnection( "jdbc:mysql://localhost:3306/dbproject?serverTimezone=UTC", "root", "xlsh5201" );
                        stmt = conn.createStatement();
                        ResultSet rs = stmt.executeQuery("select * from rating where userId ='" + id + "'");

              while(rs.next()){
                %>
                              <tr>
                                <td><%= rs.getInt("kor")%></td>
                                <td><%=rs.getString("jap")%></td>
                                <td><%=rs.getString("west")%></td>
                                <td><%=rs.getString("chin")%></td>
                                <td><%=rs.getString("bun")%></td>
                              </tr>
                            </table>
                            <hr>
                              <%
                          }
                          stmt.close(); conn.close();
                        }
                        catch( Exception ex )
                          {
                              out.println( ex.getMessage() );
                          }
                          %>

                                <button type="button" class="btn btn-info btn-block" onClick="location.href='others.jsp';">평가 랭킹</button>
                                <button type="button" class="btn btn-info btn-block" onClick="location.href='stores.jsp';">식당 보기</button>
                                <button type="button" class="btn btn-info btn-block" onClick="location.href='favorite.jsp';">단골 식당</button>
                                <button type="button" class="btn btn-info btn-block" onClick="location.href='changePWD.html';">비밀번호 변경</button>
                                <button type="button" class="btn btn-info btn-block" onClick="location.href='index.html';">로그아웃</button>
                                <button type="button" class="btn btn-info btn-block" onClick="location.href='leave.jsp';">회원 탈퇴</button>

                              </div>
                              <div class="col-3 food-right">
                                <img class="food-right" src="img/pizza.jpg"/>
                                <img class="food-right" src="img/steak.jpg"/>
                                <img class="food-right" src="img/sushi.jpg"/>
                              </div>

                                </div>

                              <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
                              <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
                              <script src="js/bootstrap.min.js"></script>
                            </body>

                          </html>
