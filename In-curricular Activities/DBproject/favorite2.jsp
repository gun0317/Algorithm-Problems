<%@page import="java.sql.*" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%

    request.setCharacterEncoding("utf-8");
    String userId = (String)session.getAttribute("id");
    String score = request.getParameter("score");
    String sName = request.getParameter("storeName");
    Connection conn;
    Statement stmt;
    boolean found = false;
    try
    {
            %><script>alert("단골 식당 추가 완료!")</script><%
        Class.forName( "com.mysql.jdbc.Driver" );
        conn = DriverManager.getConnection( "jdbc:mysql://localhost:3306/dbproject?serverTimezone=UTC", "root", "xlsh5201" );
        stmt = conn.createStatement();
        stmt.executeUpdate("INSERT INTO favorite(userId, storeName, score) VALUES('"+userId+"','"+sName+"','"+score+"')");

        %><script>alert("단골 식당 추가 완료!")</script><%

        response.sendRedirect("favorite.jsp");

        stmt.close();
        conn.close();
    }
    catch( Exception ex )
    {
        out.println( ex.getMessage() );
    }

%>
