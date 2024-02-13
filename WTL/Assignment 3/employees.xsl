<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <head>
                <style type="text/css">
                    table {
                    font-family: Arial, sans-serif;
                    border-collapse: collapse;
                    width: 100%;
                    }
                    th, td {
                    border: 1px solid #dddddd;
                    text-align: left;
                    padding: 8px;
                    }
                    th {
                    background-color: #F5F5DC;
                    }
                </style>
            </head>
            <body>
                <h2>Employee Information</h2>
                <table>
                    <tr>
                        <th>ID</th>
                        <th>Name</th>
                        <th>Position</th>
                        <th>Department</th>
                        <th>Salary</th>
                    </tr>
                    <xsl:for-each select="employees/employee">
                        <xsl:sort select="salary" order="descending"></xsl:sort>
                        <xsl:choose>
                            <xsl:when test="salary &gt; 60000">
                                <tr bgcolor="#a6f584">
                                    <td>
                                        <xsl:value-of select="id" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="name" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="position" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="department" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="salary" />
                                    </td>
                                </tr>
                            </xsl:when>
                            <xsl:when test="salary &gt; 40000">
                                <tr bgcolor="#f5e490">
                                    <td>
                                        <xsl:value-of select="id" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="name" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="position" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="department" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="salary" />
                                    </td>
                                </tr>
                            </xsl:when>
                            <xsl:otherwise>
                                <tr bgcolor="#f0b0aa">
                                    <td>
                                        <xsl:value-of select="id" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="name" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="position" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="department" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="salary" />
                                    </td>
                                </tr>
                            </xsl:otherwise>
                            <!-- <tr>
                                <td><xsl:value-of select="id"/></td>
                                <td><xsl:value-of select="name"/></td>
                                <td><xsl:value-of select="position"/></td>
                                <td><xsl:value-of select="department"/></td>
                                <td><xsl:value-of select="salary"/></td>

                                <xsl:choose>
                                    <xsl:when test="salary &gt; 60000">
                                        <td bgcolor="#a6f584">
                                            <xsl:value-of select="salary"></xsl:value-of>
                                        </td>
                                    </xsl:when>
                                    <xsl:when test="salary &gt; 40000">
                                        <td bgcolor="#f5e490">
                                            <xsl:value-of select="salary"></xsl:value-of>
                                        </td>
                                    </xsl:when>
                                    <xsl:otherwise>
                                        <td bgcolor="#f0b0aa">
                                            <xsl:value-of select="salary"></xsl:value-of>
                                        </td>
                                    </xsl:otherwise>
                                </xsl:choose>
                            </tr> -->
                        </xsl:choose>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>

</xsl:stylesheet>