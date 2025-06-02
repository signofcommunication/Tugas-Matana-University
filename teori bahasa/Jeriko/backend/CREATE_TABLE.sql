CREATE TABLE `simulation_history` (
  `id` int NOT NULL AUTO_INCREMENT,
  `input_sequence` varchar(255) NOT NULL,
  `final_state` varchar(50) NOT NULL,
  `is_accepted` tinyint(1) NOT NULL,
  `created_at` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) 
