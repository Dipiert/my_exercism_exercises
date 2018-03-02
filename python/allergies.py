class Allergies(object):

    def __init__(self, score):
        self.score = score
        self._lst = []
        self.binscore = bin(score)[2:].zfill(8)
        if (len(self.binscore) > 8):
            self.binscore = self.binscore[len(self.binscore) - 8:]
        if (self.score >= 1):
            self._all_allergies = ['cats', 'pollen', 'chocolate', 'tomatoes', 'strawberries', 'shellfish', 'peanuts', 'eggs']
            for i in range(0, len(self.binscore)):
                if self.binscore[i] == '1':
                    self._lst.append(self._all_allergies[i])

    def is_allergic_to(self, item):
        return item in self._lst

    @property
    def lst(self):
        return self._lst

