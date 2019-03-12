<%@page import="java.sql.*" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
  <%
    String kor_ = request.getParameter("kor");
    int kor = Integer.parseInt(kor_);
    String jap_ = request.getParameter("jap");
    int jap = Integer.parseInt(jap_);
    String chin_ = request.getParameter("chin");
    int chin = Integer.parseInt(chin_);
    String west_ = request.getParameter("west");
    int west = Integer.parseInt(west_);
    String bun_ = request.getParameter("bun");
    int bun = Integer.parseInt(bun_);

    String id = (String)session.getAttribute("id"); //사용자를 식별하기 위해 id를 받아옴

    Connection conn;
    Statement stmt;
    boolean found = false;

    try
    {
        int r;

        Class.forName( "com.mysql.jdbc.Driver" );
        conn = DriverManager.getConnection( "jdbc:mysql://localhost:3306/dbproject?serverTimezone=UTC", "root", "xlsh5201" );
        stmt = conn.createStatement();


        r = stmt.executeUpdate("insert into rating" + "(userId, kor, jap, chin, west, bun)" + "values('" + id + "','" + kor +"','" + jap +"','" + chin +"','" + west +"','" + bun + "')");


        if( r>0 ){
            %>
      <script>
        alert("음식평가에 성공하였습니다. 로그인 해주세요.");
        location.replace("index.html")
      </script>
    <%
        }
        else{
            %>
      <script>
        alert("음식평가에 실패하였습니다");
        history.go(-1);
      </script>
      <%
        }

        stmt.close();
        conn.close();
    }
    catch( Exception ex )
    {
        out.println( ex.getMessage() );
    }
%>
