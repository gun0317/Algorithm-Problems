<%@page import="java.sql.*" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%

    request.setCharacterEncoding("utf-8");
    String mgrId = (String)session.getAttribute("id");
    out.println("**관리자: "+mgrId);
    String sName = request.getParameter("id");
    String sLoc = request.getParameter("pwd");
    String foodType = request.getParameter("foodType");
    Connection conn;
    Statement stmt;
    boolean found = false;
    try
    {
        Class.forName( "com.mysql.jdbc.Driver" );
        conn = DriverManager.getConnection( "jdbc:mysql://localhost:3306/dbproject?serverTimezone=UTC", "root", "xlsh5201" );
        stmt = conn.createStatement();
        int r2 = stmt.executeUpdate("INSERT INTO store(storeName, loc, foodType, mgrId) VALUES('"+sName+"','"+sLoc+"','"+foodType+"','"+mgrId+"')");

        %><script>alert("식당 추가 완료!")</script><%

        response.sendRedirect("ManagerMenu.jsp");

        stmt.close();
        conn.close();
    }
    catch( Exception ex )
    {
        out.println( ex.getMessage() );
    }

%>
