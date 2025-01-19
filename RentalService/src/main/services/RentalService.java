package main.services;

import main.models.Vehicle;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class RentalService {
    private List<Vehicle> vehicles; // List of available vehicles

    public RentalService() {
        this.vehicles = new ArrayList<>();
    }

    public void addVehicle(Vehicle vehicle) {
        if (!vehicles.contains(vehicle)) {
            vehicles.add(vehicle);
        } else {
            System.out.println("Vehicle already exists in the fleet.");
        }
    }

    public Optional<Vehicle> findVehicleByLicensePlate(String licensePlate) {
        for (Vehicle vehicle : vehicles) {
            if (vehicle.getLicensePlate().equals(licensePlate)) {
                return Optional.of(vehicle);
            }
        }
        return Optional.empty();
    }

    public double calculateTotalIncome(int days) {
        double totalIncome = 0;
        for (Vehicle vehicle : vehicles) {
            totalIncome += vehicle.calculateRentalCost(days);
        }
        return totalIncome;
    }
}
