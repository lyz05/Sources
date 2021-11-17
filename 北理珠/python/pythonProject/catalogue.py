from country import Country



class CountryCatalogue:
    country_cat = {}
    header = []
    reorder = {}

    def __init__(self, country_file):
        with open(country_file,"r",encoding='utf-8') as file:
            line = file.readline().rstrip('\n')
            header = line.split("|")
            self.header = header
            for i in range(4):
                self.reorder[header[i]] = i
            print(self.reorder)
            print(header[1])
            line = file.readline().rstrip('\n')
            while (line):
                line_list = line.split("|")
                country = Country(line_list[self.reorder['Country']], line_list[self.reorder['Population']], line_list[self.reorder['Area']], line_list[self.reorder['Continent']])
                self.country_cat[country.name] = country
                line = file.readline().rstrip('\n')

    def set_country_population(self,country):
        population = country.population
        self.country_cat[country.name].population = population

    def set_country_area(self,country):
        self.country_cat[country.name].area = country.area

    def set_country_continent(self,country):
        self.country_cat[country.name].continent = country.continent

    def find_country(self,country):
        return self.country_cat[country.name]

    def add_country(self, country_name, pop, area, cont):
        country = Country(country_name, pop, area, cont)
        self.country_cat[country.name] = country

    def print_country_catalogue(self):
        print(list(self.country_cat.values()))

    def save_country_catalogue(self, fname):
        with open(fname,"w",encoding='utf-8') as file:
            file.write("|".join(self.header)+'\n')
            values = self.country_cat.values()
            for value in values:
                print(value)


countrycatalogue = CountryCatalogue("data.txt")
countrycatalogue.print_country_catalogue()
countrycatalogue.save_country_catalogue("data2.txt")