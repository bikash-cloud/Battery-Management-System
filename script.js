const cards = document.querySelectorAll(".card");

cards.forEach(card => {
  card.addEventListener("mouseenter", () => {
    card.style.background = "#334155";
  });

  card.addEventListener("mouseleave", () => {
    card.style.background = "#1e293b";
  });
});

console.log("Battery Intelligence Engine Website Loaded Successfully");
