<%@page import="java.sql.*" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%

    request.setCharacterEncoding("utf-8");

    String myid = request.getParameter("id");
    String mypassword = request.getParameter("pwd");
    String myage = request.getParameter("age");
    String mygender = request.getParameter("gender");
    String myloc = request.getParameter("loc");

    Connection conn;
    Statement stmt;
    boolean found = false;

    try
    {
        int r;

        Class.forName( "com.mysql.jdbc.Driver" );
        conn = DriverManager.getConnection( "jdbc:mysql://localhost:3306/dbproject?serverTimezone=UTC", "root", "xlsh5201" );
        stmt = conn.createStatement();


        ResultSet rs = stmt.executeQuery("select * from user_info");
        while(rs.next()){
          if(rs.getString("userId").equals(myid)){
            %> <script> alert("이미 존재하는 아이디입니다. 아이디를 바꿔주세요"); history.go(-1); </script> <%
            stmt.close();
            conn.close();
            return;
          };
        }

        int age = Integer.parseInt(myage);

        r = stmt.executeUpdate("insert into user_info" + "(userId, password, age, sex, loc)" + "values('" + myid + "','" + mypassword + "','" + age + "','" + mygender + "','" + myloc+ "')");


        if( r>0 ){
           session.setAttribute("id", myid);
            %> <script> alert("회원가입에 성공하였습니다. 음식을 평가해주세요."); location.replace("food_rating.html") </script> <%
        }
        else{
            %> <script> alert("회원가입에 실패하였습니다"); history.go(-1); </script> <%
        }

        stmt.close();
        conn.close();
    }
    catch( Exception ex )
    {
        out.println( ex.getMessage() );
    }

%>
