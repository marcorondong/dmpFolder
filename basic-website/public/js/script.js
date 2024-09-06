document.addEventListener("DOMContentLoaded", function () {
	const greetButton = document.getElementById("greetButton");
	const registerButton = document.getElementById("registerButton");
	const searchButton = document.getElementById("searchButton");
	const displayButton = document.getElementById("displayButton");
	const nameInput = document.getElementById("nameInput");
	const emailInput = document.getElementById("emailInput");
	const output = document.getElementById("output");

	// Function to reset the page state without reloading
	function resetPage() {
		nameInput.value = ''; // Clear the form field
		emailInput.value = ''; // Clear the email field
		output.textContent = ''; // Clear the output message
	}

	// Function to clear the output area before any action
	function clearOutput() {
		output.textContent = ''; // Clear the output message
	}

	// Handle Greet button click
	greetButton.addEventListener("click", function () {
		clearOutput(); // Clear output area before showing new message
		if (nameInput.checkValidity()) {
			const name = nameInput.value;
			output.textContent = `Hello, ${name}!`; // Display greeting message
			nameInput.value = ''; // Clear name input field
		} else {
			nameInput.reportValidity();
		}
	});

	// Helper function to strip HTML tags from a string
	function stripHtmlTags(str) {
		return str.replace(/<\/?[^>]+(>|$)/g, ""); // Basic regex to remove HTML tags
	}

	// Handle Register button click (POST request)
	registerButton.addEventListener("click", function () {
		clearOutput(); // Clear output area before action
		const name = nameInput.value;
		const email = emailInput.value;
		if (name && email) {
			fetch(`../../cgi-bin/register_name.cgi`, {
				method: 'POST',
				headers: {
					'Content-Type': 'application/x-www-form-urlencoded',
				},
				body: `name=${encodeURIComponent(name)}&email=${encodeURIComponent(email)}`
			})
				.then(response => response.text())
				.then(data => {
					alert('Name and email registered successfully!');
					resetPage(); 
				})
				.catch(error => {
					console.error('Error registering name:', error);
				});
		} else {
			nameInput.reportValidity();
			emailInput.reportValidity();
		}
	});

	// Handle Search button click (GET request)
	searchButton.addEventListener("click", function () {
		clearOutput(); // Clear output area before showing search result
		const name = nameInput.value;
		if (name) {
			fetch(`../../cgi-bin/search_name.cgi?name=${encodeURIComponent(name)}`)
				.then(response => response.text())
				.then(data => {
					const cleanData = stripHtmlTags(data); // Strip HTML tags from the response
					output.textContent = `Search Result: ${cleanData}`; // Display search result on the page
					nameInput.value = ''; // Clear the name input field
				})
				.catch(error => {
					console.error('Error searching for name:', error);
				});
		} else {
			nameInput.reportValidity();
		}
	});

	// Handle Display all names button click with reload
	displayButton.addEventListener("click", function () {
		clearOutput(); // Clear output area before showing new action
		const win = window.open("../pages/database.html", "_blank");
		win.location.reload(); // Force reload to ensure updated content
		resetPage();
	});
});
