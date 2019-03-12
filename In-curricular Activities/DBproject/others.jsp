<%@page import="java.sql.*, java.util.*" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
  <!DOCTYPE html>
  <html>
    <%
  String id = (String)session.getAttribute("id"); //사용자를 식별하기 위해 id를 받아옴
  out.println("**사용자: "+id);
  Connection conn;
  Statement stmt;
  Statement stmt2;
  Statement stmt3;
  Statement stmt4;
  boolean found = false;

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
                      <hr>
                        <b style="font-size:20px;">사람들이 메긴 평균 점수</b>
                        <br>
                        <p style="font-size:10px;"> query 문:<br>select avg(kor),avg(jap),avg(west),avg(chin),avg(bun) <br>from rating
                        </p>
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
                        stmt2 = conn.createStatement();
                        stmt3 = conn.createStatement();
                        stmt4 = conn.createStatement();
                        ResultSet rs = stmt.executeQuery("select avg(kor),avg(jap),avg(west),avg(chin),avg(bun) from rating");
                        ResultSet rs2 = stmt2.executeQuery("select avg(kor),avg(jap),avg(west),avg(chin),avg(bun) from rating r,user_info u where r.userId = u.userId and u.age BETWEEN 19 and 30");
                        ResultSet rs3 = stmt3.executeQuery("select avg(kor),avg(jap),avg(west),avg(chin),avg(bun) from rating r,user_info u where r.userId = u.userId and u.sex = '여자'");
                        ResultSet rs4 = stmt4.executeQuery("select avg(kor),avg(jap),avg(west),avg(chin),avg(bun) from rating r,user_info u where r.userId = u.userId and u.sex = '남자' and u.age<30 and u.age>19");
                Double[] avg = new Double[5];
                Double[] sorted = new Double[5];
                while(rs.next()){
                  avg[0] = rs.getDouble("avg(kor)");
                  avg[1] = rs.getDouble("avg(jap)");
                  avg[2] = rs.getDouble("avg(west)");
                  avg[3] = rs.getDouble("avg(chin)");
                  avg[4] = rs.getDouble("avg(bun)");
                  for(int i=0;i<5;i++) sorted[i] = avg[i];
                %>
                              <tr>
                                <td><%=avg[0]%></td>
                                <td><%=avg[1]%></td>
                                <td><%=avg[2]%></td>
                                <td><%=avg[3]%></td>
                                <td><%=avg[4]%></td>
                              </tr>
                            </table>
                            <hr>
                            <hr><hr>
                            <b style="font-size:20px;">사람들이 가장 선호하는 음식 종류<br></b>
                            <p style="font-size:10px;"> 평균 점수 sorting
                            </p>

                            <hr>
                            ->
                            <%
                              Arrays.sort(sorted);
                              double max = sorted[4];
                              if(max == avg[0]) {%>한식 <%}
                              if(max == avg[1]) {%>일식 <%}
                              if(max == avg[2]) {%>양식 <%}
                              if(max == avg[3]) {%>중식 <%}
                              if(max == avg[4]) {%>분식 <%}
                              }
                            %><-
                            <hr><hr><hr>
                            <b style="font-size:20px;">20대가 평가한 음식 점수</b>
                            <br>
                              <p style="font-size:10px;"> query 문:<br>select avg(kor),avg(jap),avg(west),avg(chin),avg(bun) <br>from rating r,user_info u<br>where r.userId = u.userId and u.age BETWEEN 19 and 30
                              </p>
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
                                  while(rs2.next()){
                                    avg[0] = rs2.getDouble("avg(kor)");
                                    avg[1] = rs2.getDouble("avg(jap)");
                                    avg[2] = rs2.getDouble("avg(west)");
                                    avg[3] = rs2.getDouble("avg(chin)");
                                    avg[4] = rs2.getDouble("avg(bun)");
                                  }  %>
                              <tr>
                                <td><%=avg[0]%></td>
                                <td><%=avg[1]%></td>
                                <td><%=avg[2]%></td>
                                <td><%=avg[3]%></td>
                                <td><%=avg[4]%></td>
                              </tr>
                            </table>
                            <hr>
                              <hr><hr>
                              <b style="font-size:20px;">여성이 평가한 음식 점수</b>
                              <br>
                                <p style="font-size:10px;"> query 문:<br>select avg(kor),avg(jap),avg(west),avg(chin),avg(bun) <br>from rating r,user_info u<br>where r.userId = u.userId and u.sex = '여자'
                                </p>
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
                                    while(rs3.next()){
                                      avg[0] = rs3.getDouble("avg(kor)");
                                      avg[1] = rs3.getDouble("avg(jap)");
                                      avg[2] = rs3.getDouble("avg(west)");
                                      avg[3] = rs3.getDouble("avg(chin)");
                                      avg[4] = rs3.getDouble("avg(bun)");
                                    }%>
                                <tr>
                                  <td><%=avg[0]%></td>
                                  <td><%=avg[1]%></td>
                                  <td><%=avg[2]%></td>
                                  <td><%=avg[3]%></td>
                                  <td><%=avg[4]%></td>
                                </tr>
                              </table>
                              <hr>
                                <hr><hr>
                                <b style="font-size:20px;">20대 남성이 평가한 음식 점수</b>
                                <br>
                                  <p style="font-size:10px;"> query 문:<br>select avg(kor),avg(jap),avg(west),avg(chin),avg(bun) <br>from rating r,user_info u<br>where r.userId = u.userId and u.sex = '남자' and u.age<30 and u.age>19
                                  </p>
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
                                      while(rs4.next()){
                                        avg[0] = rs4.getDouble("avg(kor)");
                                        avg[1] = rs4.getDouble("avg(jap)");
                                        avg[2] = rs4.getDouble("avg(west)");
                                        avg[3] = rs4.getDouble("avg(chin)");
                                        avg[4] = rs4.getDouble("avg(bun)");
                                      }%>
                                  <tr>
                                    <td><%=avg[0]%></td>
                                    <td><%=avg[1]%></td>
                                    <td><%=avg[2]%></td>
                                    <td><%=avg[3]%></td>
                                    <td><%=avg[4]%></td>
                                  </tr>
                                </table>
                                <hr>
                              <%

                          stmt.close(); stmt2.close(); stmt3.close();stmt4.close();
                          conn.close();
                        }
                        catch( Exception ex )
                          {
                              out.println( ex.getMessage() );
                          }
                          %>


                                </div>

                              </div>
                              <div>

                                <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
                                <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
                                <script src="js/bootstrap.min.js"></script>
                              </body>

                            </html>
