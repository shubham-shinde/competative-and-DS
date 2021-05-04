let user = {
  name: "Tony",
  address: {
    personal: {
      city: "Mumbai",
      area: "Robin Street",
    },
    office: {
      city: "Stark Tech Park",
      area: {
        landmark: "Avengers Street",
      },
    },
  },
};

typeof NaN; // 'number'
typeof Infinity; // 'number'
function rec_print(obj, till) {
  Object.keys(obj)
    .reverse()
    .forEach((key) => {
      p_key = till + "_" + key;
      if (typeof obj[key] === "object") {
        rec_print(obj[key], p_key);
      } else {
        console.log(`${p_key}: ${obj[key] || ""}`);
      }
    });
}

rec_print(user, "user");
