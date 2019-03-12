<%@page import="org.python.util.PythonInterpreter, org.python.core.PyInteger" contentType="text/html;charset=UTF-8" pageEncoding="UTF-8"%>
<%

    PythonInterpreter interpreter;
    interpreter = new PythonInterpreter();
    interpreter.execfile("GoEatJSP.py");
    interpreter.exec("get_rec(1)"); 
    PyInteger result = (PyInteger)interpreter.get("a");
    int res = (int)(result.getValue());
    out.println(res);

/*
    request.setCharacterEncoding("utf-8");

    String userID = request.getParameter("userID");
    String userPW = request.getParameter("userPW");

    Connection conn;
    Statement stmt;
    boolean found = false;
//
    try
    {
        Class.forName( "com.mysql.jdbc.Driver" );
        conn = DriverManager.getConnection( "jdbc:mysql://localhost:3306/goeat?serverTimezone=UTC", "root", "xlsh5201" );
        stmt = conn.createStatement();

        ResultSet rs = stmt.executeQuery("select * from user_info");
        out.println(rs);

        while(rs.next()){
          if(rs.getString("userId").equals(userID) && rs.getString("password").equals(userPW)){
            session.setAttribute("id", rs.getString("userId"));
            session.setAttribute("name", rs.getString("userName"));
            found = true;
            break;
          };
        }
        if(found){
         %> <script> alert("로그인에 성공하였습니다"); history.go(-1); </script> <%
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
    */
%>
