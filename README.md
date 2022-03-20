<div id="top"></div>



<!-- PROJECT SHIELDS -->
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This project fetches exchange rate using [cURL](https://curl.se/libcurl/) from API [https://www.cbr-xml-daily.ru](https://www.cbr-xml-daily.ru) every 10 seconds. JSON library [https://github.com/nlohmann/json](https://github.com/nlohmann/json) then parses response to JSON format. Program prints median and average value of exchange rate at the exit.


<p align="right">(<a href="#top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

To get this program up and running on your machine, follow the simple steps below.

### Installation

1. Clone the repo to the Visual Studio with this tutorial [https://docs.microsoft.com/en-us/visualstudio/get-started/tutorial-open-project-from-repo?view=vs-2022#open-a-project-from-a-github-repo](https://docs.microsoft.com/en-us/visualstudio/get-started/tutorial-open-project-from-repo?view=vs-2022#open-a-project-from-a-github-repo)
2. Download cURL as shown in this video [https://www.youtube.com/watch?v=q_mXVZ6VJs4](https://www.youtube.com/watch?v=q_mXVZ6VJs4)
3. Include JSON library by downloading a single header file [https://github.com/nlohmann/json/blob/develop/single_include/nlohmann/json.hpp](https://github.com/nlohmann/json/blob/develop/single_include/nlohmann/json.hpp). Place it into your project's folder next to the file `print_exchange_rate.cpp`
4. Now, you can run the program

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Maria Mozgunova - [Twitter - @MariaMozgunova](https://twitter.com/MariaMozgunova) - mariiamozgunova@gmail.com

Project Link: [https://github.com/MariaMozgunova/exchange_rate.git](https://github.com/MariaMozgunova/exchange_rate.git)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [README Template](https://github.com/othneildrew/Best-README-Template)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/MariaMozgunova/exchange_rate/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/mariamozgunova/
