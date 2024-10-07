from demand_generator import DemandGenerator
from charging_allocation import ChargingAllocation

def main():
    demand_gen = DemandGenerator()  # Generate new charging demands
    charging_alloc = ChargingAllocation()  # Initialize charging allocation
    charging_alloc.display_vehicles()  # Display vehicle information
    charging_alloc.display_chargers()  # Display charger information
    charging_alloc.allocate_charging()  # Allocate charging for vehicles
    charging_alloc.print_charging()  # Print the charging allocation details

if __name__ == "__main__":
    main()
