package main;

import main.models.Car;
import main.models.Motorcycle;
import main.services.RentalService;

public class Main {
    public static void main(String[] args) {

        RentalService rentalService = new RentalService();

        Car carWithAC = new Car("CAR123", "Toyota Corolla", 50, true);
        Car carWithoutAC = new Car("CAR456", "Honda Civic", 40, false);
        Motorcycle bigBike = new Motorcycle("BIKE123", "Harley Davidson", 30, 600);
        Motorcycle smallBike = new Motorcycle("BIKE456", "Yamaha", 20, 300);

        rentalService.addVehicle(carWithAC);
        rentalService.addVehicle(carWithoutAC);
        rentalService.addVehicle(bigBike);
        rentalService.addVehicle(smallBike);

        System.out.println("Finding vehicle with license plate CAR123:");
        rentalService.findVehicleByLicensePlate("CAR123")
                .ifPresent(vehicle -> System.out.println(vehicle.getDetails()));

        System.out.println("\nFinding vehicle with license plate BIKE456:");
        rentalService.findVehicleByLicensePlate("BIKE456")
                .ifPresent(vehicle -> System.out.println(vehicle.getDetails()));

        System.out.println("\nCalculating total income for 3 days:");
        System.out.println("Total income: " + rentalService.calculateTotalIncome(3));
    }
}