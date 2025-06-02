const express = require('express');
const mysql = require('mysql2');
const cors = require('cors');
const app = express();

// Middleware
app.use(cors());
app.use(express.json());

// Koneksi ke MySQL
const db = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: '',
    database: 'motod_dfa'
});

db.connect(err => {
    if (err) throw err;
    console.log('Terhubung ke database MySQL');
});

// Endpoint untuk menyimpan simulasi
app.post('/api/simulation', (req, res) => {
    const { input_sequence, final_state, is_accepted } = req.body;
    const query = 'INSERT INTO simulation_history (input_sequence, final_state, is_accepted) VALUES (?, ?, ?)';
    db.query(query, [input_sequence, final_state, is_accepted], (err, result) => {
        if (err) {
            console.error(err);
            res.status(500).send('Error menyimpan simulasi');
        } else {
            res.status(200).send('Simulasi disimpan');
        }
    });
});

// Endpoint untuk mengambil history simulasi
app.get('/api/simulation/history', (req, res) => {
    const query = 'SELECT * FROM simulation_history ORDER BY created_at DESC';
    db.query(query, (err, results) => {
        if (err) {
            console.error(err);
            res.status(500).send('Error mengambil history');
        } else {
            res.status(200).json(results);
        }
    });
});

app.listen(3000, () => {
    console.log('Server berjalan di port 3000');
});
