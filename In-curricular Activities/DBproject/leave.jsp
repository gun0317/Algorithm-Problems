<%@page import="java.sql.*, java.io.*" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>

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
  int cnt = stmt.executeUpdate("delete from user_info where userId ='" + id + "'");
  if(cnt>0){
  %>
    <script>
      alert("회원 탈퇴 완료.");
    </script>
    <%
  response.sendRedirect("index.html");
  }
  stmt.close(); conn.close();
  }
  catch( Exception ex )
    {
        out.println( ex.getMessage() );
    }
    %>
