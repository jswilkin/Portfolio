
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class TableCreation {

	public static void main(String[] args) {
		Connection conn;

		try {
			// 1. driver loading and DB connection
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/gg", "root", "CSCE460");
			System.out.println("DB Connection Success!!");

			// 2. Write SQL queries to create DB table
			String sql1 = "CREATE TABLE employee" + "(EmployeeID int not null primary key auto_increment,"
					+ "LastName varchar(45) null," + "FirstName varchar(45) null," + "CellPhone varchar(45) null,"
							+ "ExperienceLevel varchar(45) null)";

			String sql2 = "CREATE TABLE gg_service" + "(ServiceID int(11) not null primary key auto_increment," + "ServiceDescription varchar(45) null,"
					+ "CostPerHour varchar(45) null)";

			String sql4 = "CREATE TABLE owned_property" + "(PropertyID int(11) not null primary key auto_increment," + "PropertyName varchar(45) null,"
					+ "PropertyType varchar(45) null," + "Street varchar(45) null," + "City varchar(45) null," + "State varchar(2) null,"
					+ "Zip int(5) null," + "OwnerID int(45)," + "foreign key (OwnerID) references owner(OwnerID))";

			String sql3 = "CREATE TABLE owner" + "(OwnerID int(11) not null primary key auto_increment," + "OwnerName varchar(45) null,"
					+ "OwnerEmailAddress varchar(45) null," + "OwnerType varchar(45) null)";
			
			String sql5 = "CREATE TABLE property_service" + "(PropertyServiceID int(11) not null primary key auto_increment," + "PropertyID int(11) null,"
			+ "ServiceID int(11) null," + "ServiceDate date null," + "EmployeeID int(11)," + "HoursWorked varchar(45) null,"
					+ "foreign key (EmployeeID) references employee(EmployeeID))";

			// 3. Create the statement object to execute SQL queries.
			Statement smt = conn.createStatement();

			// 4. Execute SQL query using the execute method of the statement object
			boolean result1 = smt.execute(sql1);
			boolean result2 = smt.execute(sql2);
			boolean result3 = smt.execute(sql3);
			boolean result4 = smt.execute(sql4);
			boolean result5 = smt.execute(sql5);

			System.out.println("Result: " + result1);
			System.out.println("Result: " + result2);
			System.out.println("Result: " + result3);
			System.out.println("Result: " + result4);
			System.out.println("Result: " + result5);

			// 5. Close
			if (smt != null)
				smt.close();
			if (conn != null)
				conn.close();
		} catch (Exception e) {
			System.out.println("Error: " + e);
		}

	}

}
