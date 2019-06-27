import { Component, OnInit } from '@angular/core';
import { apiCallServer } from '../../services/apicallserver/apiCallServer.service';





@Component({
    templateUrl: './login.component.html',
    styles: [`
    button[disabled] {
      opacity: 0.5;
      cursor:  not-allowed;
    }

    input[type="text"][disabled] {
      cursor: auto;
    }
  `]
})

export class LoginComponent implements OnInit {
    // Devices List
    constructor(public authService: apiCallServer) {
    }

    ngOnInit() {

    }

};