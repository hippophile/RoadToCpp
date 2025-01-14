package test;

import main.models.Car;
import main.models.Motorcycle;
import main.services.RentalService;

public class RentalServiceTestManual {

    public static void main(String[] args) {
        testCalculateRentalCost();
        testFindVehicleByLicensePlate();
        testCalculateTotalIncome();
    }

    public static void testCalculateRentalCost() {
        Car carWithAC = new Car("CAR123", "Toyota", 50, true);
        Car carWithoutAC = new Car("CAR456", "Honda", 40, false);
        Motorcycle bigBike = new Motorcycle("BIKE123", "Harley", 30, 600);
        Motorcycle smallBike = new Motorcycle("BIKE456", "Yamaha", 20, 300);

        assert carWithAC.calculateRentalCost(3) == 165.0 : "Test failed for carWithAC";
        assert carWithoutAC.calculateRentalCost(3) == 120.0 : "Test failed for carWithoutAC";
        assert bigBike.calculateRentalCost(3) == 108.0 : "Test failed for bigBike";
        assert smallBike.calculateRentalCost(3) == 60.0 : "Test failed for smallBike";

        System.out.println("testCalculateRentalCost passed!");
    }

    public static void testFindVehicleByLicensePlate() {
        RentalService rentalService = new RentalService();
        Car car = new Car("CAR123", "Toyota", 50, true);
        Motorcycle bike = new Motorcycle("BIKE123", "Harley", 30, 600);

        rentalService.addVehicle(car);
        rentalService.addVehicle(bike);

        assert rentalService.findVehicleByLicensePlate("CAR123") != null : "Test failed for CAR123";
        assert rentalService.findVehicleByLicensePlate("BIKE123") != null : "Test failed for BIKE123";
        assert rentalService.findVehicleByLicensePlate("INVALID") == null : "Test failed for INVALID";

        System.out.println("testFindVehicleByLicensePlate passed!");
    }

    public static void testCalculateTotalIncome() {
        RentalService rentalService = new RentalService();
        Car car = new Car("CAR123", "Toyota", 50, true);
        Motorcycle bike = new Motorcycle("BIKE123", "Harley", 30, 600);

        rentalService.addVehicle(car);
        rentalService.addVehicle(bike);

        assert rentalService.calculateTotalIncome(3) == 273.0 : "Test failed for total income";

        System.out.println("testCalculateTotalIncome passed!");
    }
}
