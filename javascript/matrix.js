var Matrix = function(mtx) {
    this.rows = this.extractRows(mtx);
    this.columns = this.extractCols(mtx);
}

Matrix.prototype.extractRows = function(mtx) {
    var strRows = mtx.split('\n');
    var rows = [];
    strRows.forEach((strRow) => {
        rows.push(strRow.split(' ').map(Number));   
    });
    return rows;
};

Matrix.prototype.extractCols = function(mtx) {
    var col = [];
    var cols = [];
    for(var i = 0 ; i < this.rows.length; i++) {
        for(var j = 0; j < this.rows.length; j++)
            col.push(this.rows[j][i]);              
        cols.push(col);
        col = [];
    }
    return cols;
};


module.exports = Matrix;

