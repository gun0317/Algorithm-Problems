<%@page import="java.sql.*" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%

    request.setCharacterEncoding("utf-8");

    String userID = request.getParameter("userID");
    String userPW = request.getParameter("userPW");

    Connection conn;
    Statement stmt;
    boolean found = false;

    int userIndex = -1;
    String userName = "";

    try
    {
        Class.forName( "com.mysql.jdbc.Driver" );
        conn = DriverManager.getConnection( "jdbc:mysql://localhost:3306/dbproject?serverTimezone=UTC", "root", "xlsh5201" );
        stmt = conn.createStatement();

        ResultSet rs = stmt.executeQuery("select * from user_info");
        out.println(rs);

        while(rs.next()){

          if(rs.getString("userId").equals(userID) && rs.getString("password").equals(userPW)){
            found = true;
            break;
          };
        }
        if(found){
            session.setAttribute("id", userID);
            response.sendRedirect("recommend.jsp");
        }
        else{
          %> <script> alert("로그인에 실패하였습니다"); history.go(-1); </script> <%
        }

        stmt.close();
        conn.close();
    }
    catch( Exception ex )
    {
        out.println( ex.getMessage() );
    }
%>
