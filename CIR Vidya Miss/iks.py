from flask import Flask, render_template_string

app = Flask(__name__)

@app.route("/")
def home():
    # Simple inline HTML
    return render_template_string("""
        <html>
            <head><title>Test Page</title></head>
            <body>
                <h1>Testing</h1>
                <p>This is a simple Flask page running on port 3000.</p>
            </body>
        </html>
    """)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=1234, debug=True)