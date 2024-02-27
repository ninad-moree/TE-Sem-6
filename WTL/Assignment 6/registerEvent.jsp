<%@ page import="java.io.*" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Registration Successful</title>
</head>
<body>

    <h2>Registration Successful!</h2>

    <%
        // Retrieve form data
        String name = request.getParameter("name");
        String email = request.getParameter("email");
        String selectedEvent = request.getParameter("event");

        // Display registration details
        out.println("<p>Name: " + name + "</p>");
        out.println("<p>Email: " + email + "</p>");
        out.println("<p>Event: " + selectedEvent + "</p>");
    %>

</body>
</html>
