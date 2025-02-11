# This program reads a text file with the format 
#   city name (TAB) population2011 (TAB) population2018 (TAB) area(km2)
# into a list and creates a new file with the population by km2:
#   city name, area, population_by_km2_2011, population_by_km2_2018. 
# The result is sorted by city name and the field separator is comma 
# instead of TAB.

def main():
    ### Read the text file
    stats = loadPopulationFile("cities.txt")
    
    ### sorts the list by city name
    stats.sort()
    
    ### Write the list into a file
    saveDensityFile("cities_new_1.txt")
    
def loadPopulationFile(filename):
    # open the file for reading
    fin = open(filename)
    header = fin.readline()  # reads (and ignores) the first line

    # create an empty list to store the results
    stats = []

    # read file line by line
    for line in fin:
        # strip whitespaces and split the line into 4 attributes
        attribs = line.strip().split("\t")

        # give a name to each attribute; 
        # not really necessary but the program is easier to read
        city = attribs[0]
        pop2011 = int(attribs[1])
        pop2018 = int(attribs[2])
        areaKm2 = float(attribs[3])

        # compute the population by km2
        pop2011_km2 = pop2011 / areaKm2
        pop2018_km2 = pop2018 / areaKm2

        # append a new tuple to the results list
        stats.append((city, areaKm2, pop2011_km2, pop2018_km2))
        
    # do not forget to close the file after reading all lines
    fin.close() 
    return stats



def saveDensityFile(filename):
    # open the file for writing
    fout = open(filename, "w")

    # writes each tuple in stats into the file
    for t in stats:
        fout.writelines("{},{:.3f},{:.2f},{:.2f}\n".format(t[0], t[1], t[2], t[3]))

    # Do not forget to close the file 
    fout.close()


if __name__ == "__main__":
    main()
