document.addEventListener("DOMContentLoaded", function () {
	const uploadForm = document.getElementById('uploadForm');
	const fileInput = document.getElementById('fileInput');
	const fileList = document.getElementById('fileList');

	// Fetch and display the list of files
	function fetchFiles() {
		fetch('../../cgi-bin/list_files.cgi')
			.then(response => response.json())
			.then(files => {
				updateFileList(files); // Use the common function to format and display files
			})
			.catch(error => console.error('Error fetching files:', error));
	}

	// Common function to format and display files
	function updateFileList(files) {
		fileList.innerHTML = ''; // Clear the current list
		files.forEach(file => {
			const truncatedName = truncateFileName(file, 40); // Truncate filenames
			const fileItem = document.createElement('div');
			fileItem.className = 'file-item';
			fileItem.innerHTML = `
				<a href="../uploads/${file}" target="_blank">${truncatedName}</a>
				<button data-file="${file}" class="delete-button">Delete</button>
			`;
			fileList.appendChild(fileItem);
		});

		// Add event listeners to delete buttons
		attachDeleteEventListeners();
	}

	// Function to truncate file names
	function truncateFileName(fileName, maxLength) {
		const extension = fileName.slice(fileName.lastIndexOf('.')); // Get the file extension
		const baseName = fileName.slice(0, fileName.lastIndexOf('.')); // Get the base name
		if (fileName.length > maxLength) {
			return `${baseName.slice(0, maxLength - extension.length - 3)}...${extension}`; // Truncate and add "..."
		}
		return fileName;
	}

	// Handle file upload
	uploadForm.addEventListener('submit', function (event) {
		event.preventDefault();
		const formData = new FormData();
		formData.append('file', fileInput.files[0]);

		fetch('../../cgi-bin/upload_file.cgi', {
			method: 'POST',
			body: formData,
		})
			.then(response => response.json())
			.then(files => {
				// alert('File uploaded successfully!');
				fileInput.value = ''; // Clear the file input field after upload
				updateFileList(files); // Use the response to update the file list
			})
			.catch(error => console.error('Error uploading file:', error));
	});

	// Handle file deletion using GET request
	function deleteFile(fileName) {
		fetch(`../../cgi-bin/delete_file.cgi?file=${encodeURIComponent(fileName)}`, {
			method: 'GET', // Use GET instead of DELETE
		})
		.then(response => response.json())
		.then(files => {
			// alert('File deleted successfully!'); // Show success message
			updateFileList(files); // Use the response to update the file list
		})
		.catch(error => console.error('Error deleting file:', error));
	}

	// Attach event listeners to delete buttons
	function attachDeleteEventListeners() {
		document.querySelectorAll('.delete-button').forEach(button => {
			button.addEventListener('click', function () {
				const fileName = this.getAttribute('data-file');
				deleteFile(fileName);
			});
		});
	}

	// Initial fetch of files when the page loads
	fetchFiles();
});
