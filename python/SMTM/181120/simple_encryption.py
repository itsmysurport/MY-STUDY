class Password():
    def __init__(self):
        self.key = "zaq/']xsw.;[,lpmkonjidcebhuvfrgyt!@#$^&*()-=1234567890_+"
        self.value = "AB?C!DEFGHIJKLMNOPQRSTUVW XYZabcdefghijklmnopqrstuvw-xyz"
        self.key_table = { }
        self.value_table = { }
        self.encodeStr = ''
        self.decodeStr = ''

        for i in range (0, len(self.key)):
            self.key_table[self.key[i]] = self.value[i]
            self.value_table[self.value[i]] = self.key[i]

    def encoding(self, tempStr):
        self.encodeStr = ''
        for i in range (0, len(tempStr)):
            self.encodeStr += self.value_table[tempStr[i]]
        print(self.encodeStr)

    def decoding(self, tempStr):
        self.decodeStr = ''
        for i in range (0, len(tempStr)):
            self.decodeStr += self.key_table[tempStr[i]]
        print(self.decodeStr)


homework = Password()
tempStr = 'Su-Ha Lee'
homework.encoding(tempStr)
tempStr = 'i69.rhl!!'
homework.decoding(tempStr)
