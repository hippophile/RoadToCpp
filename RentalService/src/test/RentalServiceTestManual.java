package test;

import main.models.Car;
import main.models.Motorcycle;
import main.services.RentalService;


// I know this is not what you asked for the tests. Unfortunately i was having problems that i could not fix with JUnit5
// so instead I went for manual testing...

public class RentalServiceTestManual {

    public static void main(String[] args) {
        testCalculateRentalCost();
        testFindVehicleByLicensePlate();
        testCalculateTotalIncome();
    }

    // Tests the calculateRentalCost function for different vehicles
    public static void testCalculateRentalCost() {
        Car carWithAC = new Car("CAR123", "Toyota", 50, true);
        Car carWithoutAC = new Car("CAR456", "Honda", 40, false);
        Motorcycle bigBike = new Motorcycle("BIKE123", "Harley", 30, 600);
        Motorcycle smallBike = new Motorcycle("BIKE456", "Yamaha", 20, 300);

        assert carWithAC.calculateRentalCost(3) == 165.0 : 
            "Test failed for carWithAC. Expected 165.0, got " + carWithAC.calculateRentalCost(3);
        assert carWithoutAC.calculateRentalCost(3) == 120.0 : 
            "Test failed for carWithoutAC. Expected 120.0, got " + carWithoutAC.calculateRentalCost(3);
        assert bigBike.calculateRentalCost(3) == 108.0 : 
            "Test failed for bigBike. Expected 108.0, got " + bigBike.calculateRentalCost(3);
        assert smallBike.calculateRentalCost(3) == 60.0 : 
            "Test failed for smallBike. Expected 60.0, got " + smallBike.calculateRentalCost(3);

        System.out.println("testCalculateRentalCost passed!");
    }

    // Tests the findVehicleByLicensePlate functoin with existing and non existing vehicles
    public static void testFindVehicleByLicensePlate() {
        RentalService rentalService = new RentalService();
        Car car = new Car("CAR123", "Toyota", 50, true);
        Motorcycle bike = new Motorcycle("BIKE123", "Harley", 30, 600);

        rentalService.addVehicle(car);
        rentalService.addVehicle(bike);

        assert rentalService.findVehicleByLicensePlate("CAR123") != null : 
            "Test failed for CAR123. Vehicle not found.";
        assert rentalService.findVehicleByLicensePlate("BIKE123") != null : 
            "Test failed for BIKE123. Vehicle not found.";
        assert rentalService.findVehicleByLicensePlate("INVALID") == null : 
            "Test failed for INVALID. Expected null, found a vehicle.";

        System.out.println("testFindVehicleByLicensePlate passed!");
    }

    // Tests the calculateTotalIncome function for many vehicles
    public static void testCalculateTotalIncome() {
        RentalService rentalService = new RentalService();
        Car car = new Car("CAR123", "Toyota", 50, true);
        Motorcycle bike = new Motorcycle("BIKE123", "Harley", 30, 600);

        rentalService.addVehicle(car);
        rentalService.addVehicle(bike);

        double totalIncome = rentalService.calculateTotalIncome(3);
        assert totalIncome == 273.0 : 
            "Test failed for total income. Expected 273.0, got " + totalIncome;

        System.out.println("testCalculateTotalIncome passed!");
    }
}
