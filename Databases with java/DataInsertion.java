
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class DataInsertion {

	public static void main(String[] args) {
		Connection conn;

		try
		{
			//1. Driver loading and DB connection
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/gg", "root", "CSCE460");
			System.out.println("Successful DB Connection");
			
			//2. Write SQL query
			String sql1 = "INSERT INTO employee"
					+ " VALUES (1, 'Smith', 'Sam', '206-254-1234', 'Master'),"
					+ "(2, 'Evanston', 'John', '206-254-2345', 'Senior'),"
					+ "(3, 'Murray', 'Dale', '206-254-3456', 'Junior'),"
					+ "(4, 'Murphy', 'Jerry', '585-545-8765', 'Master'),"
					+ "(5, 'Fontaine', 'Joan', '206-254-4567', 'Senior')";
			
			String sql2 = "INSERT INTO gg_service"
					+ " VALUES (1, 'Mow Lawn', '25.00'),"
					+ "(2, 'Plant Annuals', '25.00'),"
					+ "(3, 'Weed Garden', '30.00'),"
					+ "(4, 'Trim Hedge', '45.00'),"
					+ "(5, 'Prune Small Tree', '60.00'),"
					+ "(6, 'Trim Medium Tree', '100.00'),"
					+ "(7, 'Trim Large Tree', '125.00')";
			
			String sql4 = "INSERT INTO owned_property"
					+ " VALUES (1, 'Eastlake Building', 'Office', '123 Eastlake', 'Seattle', 'WA', 98119, 2),"
					+ "(2, 'Elm St Apts', 'Apartments', '4 East Elm', 'Lynwood', 'WA', 98223, 1),"
					+ "(3, 'Jefferson Hill', 'Offices', '42 West 7th St', 'Bellevue', 'WA', 98007, 2),"
					+ "(4, 'Lake View Apts', 'Apartments', '1265 32nd Avenue', 'Redmond', 'WA', 98052, 3),"
					+ "(5, 'Kodak Heights Apts', 'Apartments', '63 32nd Avenue', 'Redmond', 'WA', 98052, 4),"
					+ "(6, 'Jones House', 'Private Residence', '1456 48th St', 'Bellevue', 'WA', 98007, 1),"
					+ "(7, 'Douglas House', 'Private Residence', '1567 51st St', 'Bellevue', 'WA', 98007, 3),"
					+ "(8, 'Samuels House', 'Private Residence', '567 151st St', 'Redmond', 'WA', 98052, 5),"
					+ "(9, 'Oak St Apts', 'Apartments', '5 West Oak', 'Lynwood', 'WA', 98223, 1)";
			
			String sql3 = "INSERT INTO owner"
					+ " VALUES (1, 'Mary Jones', 'Mary.Jones@somewhere.com', 'Individual'),"
					+ "(2, 'DT Enterprises', 'DTE@dte.com', 'Corporation'),"
					+ "(3, 'Sam Douglas', 'Sam.Douglas@somewhere.com', 'Individual'),"
					+ "(4, 'UNY Enterprises', 'UNYE@unye.com', 'Corporation'),"
					+ "(5, 'Doug Samuels', 'Doug.Samuels@somewhere.com', 'Individual')";
			
			String sql5 = "INSERT INTO property_service"
					+ " VALUES (1, 1, 2, '2017-05-05', 1, '4.50'),"
					+ "(2, 3, 2, '2017-05-08', 3, '4.50'),"
					+ "(3, 2, 1, '2017-05-08', 2, '2.75'),"
					+ "(4, 6, 1, '2017-05-10', 5, '2.50'),"
					+ "(5, 5, 4, '2017-05-12', 4, '7.50'),"
					+ "(6, 8, 1, '2017-05-15', 4, '2.75'),"
					+ "(7, 4, 4, '2017-05-19', 1, '1.00'),"
					+ "(8, 7, 1, '2017-05-21', 2, '2.50'),"
					+ "(9, 6, 3, '2017-06-03', 5, '2.50'),"
					+ "(10, 5, 7, '2017-06-08', 4, '10.50'),"
					+ "(11, 8, 3, '2017-06-12', 4, '2.75'),"
					+ "(12, 4, 5, '2017-06-15', 1, '5.00'),"
					+ "(13, 7, 3, '2017-06-19', 2, '4.00')";
			
			//3. Create the statement object to execute SQL query
			Statement stmt = conn.createStatement();
			
			//4. Execute SQL query using the execute(String sql) method of the Statement object
			boolean result1 = stmt.execute(sql1);
			boolean result2 = stmt.execute(sql2);
			boolean result3 = stmt.execute(sql3);
			boolean result4 = stmt.execute(sql4);
			boolean result5 = stmt.execute(sql5);
			System.out.println("Inserting data is successful!");
			
			//5. close
			if(stmt!=null)
				stmt.close();
			if(conn!=null)
				conn.close();
		}
		catch(Exception e)
		{
			System.out.println("Error: "+e);
		}
	}
}
