class Country:
    name = ""
    population = ""
    area = ""
    continent = ""

    def __init__(self, name, pop, area, continent):
        self.name = name
        self.population = pop
        self.area = area
        self.continent = continent

    def get_name(self):
        return self.name

    def get_population(self):
        return self.population

    def get_area(self):
        return self.area

    def get_continent(self):
        return self.continent

    def set_population(self, pop):
        self.population = pop

    def set_area(self, area):
        self.area = area

    def set_continent(self, continent):
        self.continent = continent

    def __repr__(self) -> str:
        return "{} (pop: {}, size: {}) in {}".format(self.name, self.population, self.area, self.continent)
