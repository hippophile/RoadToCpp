package main.models;

public class Car extends Vehicle {
    private boolean hasAirConditioning;

    public Car(String licensePlate, String model, double dailyRate, boolean hasAirConditioning) {
        super(licensePlate, model, dailyRate);
        this.hasAirConditioning = hasAirConditioning;
    }

    public boolean hasAirConditioning() {
        return hasAirConditioning;
    }

    @Override
    public double calculateRentalCost(int days) {
        double cost = days * getDailyRate();
        if (hasAirConditioning) {
            cost += cost * 0.10; // Adds 10% if air conditioning is present!!!
        }
        return cost;
    }
}
