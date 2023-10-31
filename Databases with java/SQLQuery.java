
import java.sql.*;

public class SQLQuery {

	public static void main(String[] args) {
		Connection conn;

		try {
			// 1. Driver loading and DB connection
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/gg", "root", "CSCE460");
			System.out.println("Successful DB Connection");

			// 2. Write SQL query
			String sql1 = "SELECT LastName, FirstName, CellPhone " 
							+ "FROM employee "
							+ "WHERE ExperienceLevel = 'Master' AND FirstName REGEXP '^J'";
			String sql2 = "SELECT ServiceID, SUM(HoursWorked) AS TotalHoursWorked, AVG(HoursWorked) AS AvgHoursWorked " 
							+ "FROM property_service " 
							+ "GROUP BY ServiceID "
							+ "ORDER BY ServiceID";
			String sql3 = "SELECT PropertyName "
					+ "FROM owned_property "
					+ "WHERE PropertyType = 'Private Residence' AND City = 'Bellevue'";
			String sql4 = "SELECT PropertyName "
					+ "FROM owned_property "
					+ "WHERE PropertyName REGEXP '^K' OR PropertyName REGEXP '^L'";
			String sql5 = "SELECT P.EmployeeID, P.PropertyID, (P.HoursWorked * 8.00) AS TotalCost " 
					+ "FROM property_service P "
					+ "JOIN gg_service G "
					+ "ON P.ServiceID = G.ServiceID "
					+ "WHERE G.ServiceDescription = 'Trim Large Tree'";

			// 3. Create the statement object to execute SQL query
			Statement stmt = conn.createStatement();

			// 4. Execute SQL query using the execute method
			ResultSet rs1 = stmt.executeQuery(sql1);

			System.out.println("===Question a Output===");
			while (rs1.next()) {
				String LastName = rs1.getString("LastName");
				String FirstName = rs1.getString("FirstName");
				String CellPhone = rs1.getString("CellPhone");

				System.out.println("LastName: " + LastName + "\n" + "FirstName: " + FirstName + "\n" + "CellPhone: " + CellPhone);
			}

			System.out.println("===Question b Output===");
			ResultSet rs2 = stmt.executeQuery(sql2);
			while (rs2.next()) {
				int ServiceID = rs2.getInt("ServiceID");
				String TotalHoursWorked = rs2.getString("TotalHoursWorked");
				String AvgHoursWorked = rs2.getString("AvgHoursWorked");
				
				System.out.println("ServiceID: " + ServiceID + "\n" + "TotalHoursWorked: " + TotalHoursWorked + "\n" + "AvgHoursWorked: "
				+ AvgHoursWorked);
			}
			
			System.out.println("===Question c Output===");
			ResultSet rs3 = stmt.executeQuery(sql3);
			while (rs3.next()) {
				String PropertyName = rs3.getString("PropertyName");

				System.out.println("PropertyName: " + PropertyName + "\n");
			}
			
			System.out.println("===Question d Output===");
			ResultSet rs4 = stmt.executeQuery(sql4);
			while (rs4.next()) {
				String PropertyName = rs4.getString("PropertyName");

				System.out.println("PropertyName: " + PropertyName + "\n");
			}
			
			System.out.println("===Question e Output===");
			ResultSet rs5 = stmt.executeQuery(sql5);
			while (rs5.next()) {
				int EmployeeID = rs5.getInt("EmployeeID");
				int PropertyID = rs5.getInt("PropertyID");
				String TotalCost = rs5.getString("TotalCost");
				
				System.out.println("EmployeeID: " + EmployeeID + "\n" + "PropertyID: " + PropertyID + "\n" 
				+ "TotalCost: " + TotalCost);
			}

			// 5. close
			if (stmt != null)
				stmt.close();
			if (conn != null)
				conn.close();
		} catch (Exception e) {
			System.out.println("Error: " + e);
		}
	}
}
