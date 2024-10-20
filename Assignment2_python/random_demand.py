from demand_generator import DemandGenerator
from charging_allocation import ChargingAllocation

def main():
    demand_gen = DemandGenerator() 
    charging_alloc = ChargingAllocation() 
    charging_alloc.display_vehicles() 
    charging_alloc.display_chargers()  
    charging_alloc.allocate_charging()  
    charging_alloc.print_charging()  

if __name__ == "__main__":
    main()
