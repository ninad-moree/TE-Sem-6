function validateLogin() {
  var registerUsername = document.getElementById('loginUsername').value;
  var registerPassword = document.getElementById('loginPassword').value;

  alert('Login\nUsername: ' + registerUsername + '\nPassword: ' + registerPassword);
}

function validateRegister() {
  var registerUsername = document.getElementById('registerUsername').value;
  var registerPassword = document.getElementById('registerPassword').value;
  var confirmPassword = document.getElementById('confirmPassword').value;
  var email = document.getElementById('email').value;
  var phone = document.getElementById('phone').value;

  if (registerUsername === '' || email === '' || phone === '' || registerPassword === '' || confirmPassword === '') {
    alert('All fields are required.');
  } else if (!isValidEmail(email)) {
    alert('Invalid email address.');
  } else if (!isValidPhoneNumber(phone)) {
    alert('Invalid phone number. Please enter a valid 10-digit phone number.');
  } else if (registerPassword !== confirmPassword) {
    alert('Password and Confirm Password must match.');
  } else {

    alert('Registration successful!');
    window.location.href = 'login.html';
  }
}


function openLoginPage() {
  window.location.href = 'login.html';
}

function openRegisterPage() {
  window.location.href = 'register.html';
}

function isValidEmail(email) {
  var emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
  return emailRegex.test(email);
}

function isValidPhoneNumber(phone) {
  var phoneRegex = /^\d{10}$/;
  return phoneRegex.test(phone);
}