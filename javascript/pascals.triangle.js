function Triangle(cantRows) {
    this.cantRows = cantRows;
    this.rows = [];
    this.fillRows();
    this.lastRow = this.rows[this.rows.length - 1];
}

Triangle.prototype.fillRows = function() {
    this.rows.push([1]);
    for (var numRow = 1; numRow < this.cantRows; numRow++) {
        this.rows.push(this.fillRow(numRow));
    }
}

Triangle.prototype.fillRow = function (numRow) {
    var row = [];
    var rowLength = numRow + 1; 
    var pastRow = this.rows[numRow - 1];
    for (var i = 0; i < rowLength; i++) {
        if (this.isBorderCell(pastRow, i)) {
            row.push(1);
        } else {
            var newValue = pastRow[i - 1] + pastRow[i];
            row.push(newValue);
        }           
    }
    return row;
}

Triangle.prototype.isBorderCell = function (row, index) {
    return (row[index - 1] === undefined || row[index] === undefined);
}

module.exports = Triangle;

