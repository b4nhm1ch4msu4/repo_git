# Expense Tracker API

A backend REST API for tracking income, expenses, categories, and monthly financial summaries.

## Tech Stack

- Python
- FastAPI
- SQLite
- SQLAlchemy
- JWT Authentication

## Features

- User registration and login
- JWT-based authentication
- Create, read, update, and delete transactions
- Category management
- Monthly income/expense summary
- User-specific data protection

## API Examples

POST /auth/register
POST /auth/login
GET /transactions
POST /transactions
GET /summary/monthly?year=2026&month=8

## How to Run

1. Clone the repository
2. Create a virtual environment
3. Install dependencies
4. Run the server


## Suggested folder structure

expense-tracker-api/
│
├── app/
│   ├── main.py
│   ├── database.py
│   ├── models.py
│   ├── schemas.py
│   ├── auth.py
│   ├── dependencies.py
│   │
│   ├── routers/
│   │   ├── auth.py
│   │   ├── users.py
│   │   ├── transactions.py
│   │   ├── categories.py
│   │   └── summary.py
│   │
│   └── services/
│       └── summary_service.py
│
├── tests/
│   └── test_transactions.py
│
├── requirements.txt
├── .env.example
├── README.md
└── .gitignore
